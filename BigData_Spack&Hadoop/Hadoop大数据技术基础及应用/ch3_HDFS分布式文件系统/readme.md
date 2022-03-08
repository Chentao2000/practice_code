第三章 ： HDFS 分布式文件系统
--

### 1. HDFS的设计理念是什么？
  
1） 可构建在廉价机器上
HDFS 的设计理念之一就是让它能运行在普通的硬件之上，即便硬件出现故障，也可以通过容错策略来保证数据的高可用性。
2）高容错性
由于 HDFS 需要建立在普通计算机上，所以结点故障是正常的事情。HDFS 将数据自动保存多个副本，副本丢失后，自动恢复，从而实现数据的高容错性。
3）适合批处理
HDFS 适合一次写入、多次查询（读取）的情况。在数据集生成后，需要长时间在此数据集上进行各种分析。每次分析都将涉及该数据集的大部分数据甚至全部数据，因此读取整个数据集的时间延迟比读取第一条记录的时间延迟更重要。
4） 适合存储大文件
这里说的大文件包含两种意思：一是值文件大小超过 100MB 及达到 GB 甚至 TB、PB 级的文件;二是百万规模以上的文件数量
  
###  2. SecondaryName 和 NameNode 的交互过程是什么？

SecondaryNameNode的作用就是帮助NameNode进行Edits和Fsimage的合并工作。

SecondaryNameNode首先会询问NameNode是否需要CheckPoint（触发CheckPoint需要满足两个条件中的任意一个，定时时间到和Edits中数据写满了）
直接带回NameNode是否检查结果。

SecondaryNameNode执行CheckPoint操作，首先会让NameNode滚动Edits并生成一个空的edits.inprogress，滚动Edits的目的是给Edits打个标记，以后所有新的操作都写入edits.inprogress，

其他未合并的Edits和Fsimage会拷贝到SecondaryNameNode的本地，然后将拷贝的Edits和Fsimage加载到内存中进行合并，生成fsimage.chkpoint，

然后将fsimage.chkpoint拷贝给NameNode，重命名为Fsimage后替换掉原来的Fsimage。

NameNode在启动时就只需要加载之前未合并的Edits和Fsimage即可，因为合并过的Edits中的元数据信息已经被记录在Fsimage中。


###  3. HDFS的优缺点是什么？

- 省略

 ###  4. HDFS的数据读写流程是什么？

 ##### 读流程：
1. 客户端向NameNode发出写文件请求。

2. 检查是否已存在文件、检查权限。若通过检查，直接先将操作写入EditLog，并返回输出流对象。
- （注：WAL，write ahead log，先写Log，再写内存，因为EditLog记录的是最新的HDFS客户端执行所有的写操作。如果后续真实写操作失败了，由于在真实写操作之前，操作就被写入EditLog中了，故EditLog中仍会有记录，我们不用担心后续client读不到相应的数据块，因为在第5步中DataNode收到块后会有一返回确认信息，若没写成功，发送端没收到确认信息，会一直重试，直到成功）

3. client端按128MB的块切分文件。

client将NameNode返回的分配的可写的DataNode列表和Data数据一同发送给最近的第一个DataNode节点，此后client端和NameNode分配的多个DataNode构成pipeline管道，client端向输出流对象中写数据。client每向第一个DataNode写入一个packet，这个packet便会直接在pipeline里传给第二个、第三个…DataNode。
- （注：并不是写好一个块或一整个文件后才向后分发）

4. 每个DataNode写完一个块后，会返回确认信息。
（注：并不是每写完一个packet后就返回确认信息，个人觉得因为packet中的每个chunk都携带校验信息，没必要每写一个就汇报一下，这样效率太慢。正确的做法是写完一个block块后，对校验信息进行汇总分析，就能得出是否有块写错的情况发生）

5. 写完数据，关闭输输出流。发送完成信号给NameNode。

- （注：发送完成信号的时机取决于集群是强一致性还是最终一致性，强一致性则需要所有DataNode写完后才向NameNode汇报。最终一致性则其中任意一个DataNode写完后就能单独向NameNode汇报，HDFS一般情况下都是强调强一致性）

##### 读流程 ：

1.client访问NameNode，查询元数据信息，获得这个文件的数据块位置列表，返回输入流对象。
   
2.就近挑选一台datanode服务器，请求建立输入流 。
   
3.DataNode向输入流中中写数据，以packet为单位来校验。
  
4.关闭输入流



 ###  5. HDFS的副本策略是是什么？

- HDFS采用一种称为机架感知的策略来改进数据的可靠性、可用性和网络带宽的利用率。
- 通过一个机架感知的过程，NameNode可以确定每一个DataNode所属的机架id
- (这也是NameNode采用NetworkTopology数据结构来存储数据节点的原因，也是我在前面详细介绍NetworkTopology类的原因)。
- 一个简单但没有优化的策略就是将副本存放在不同的机架上，这样可以防止当整个机架失效时数据的丢失，并且允许读数据的时候充分利用多个机架的带宽。
- 这种策略设置可以将副本均匀分布在集群中，有利于当组件失效的情况下的均匀负载，但是，因为这种策略的一个写操作需要传输到多个机架，这增加了写的代价。
 
 
 ### 6. HDFS的HA(高可用)机制是什么？



