
public class AdvertisementBoard{ // 负责创造广告板

    public void show(Advertisement adver){
       System.out.println(adver.getCorpName() + "的广告词如下 :");
        adver.showAdvertisement(); //接口回调 
    }
}
