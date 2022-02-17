import re
from matplotlib.pyplot import hist
from skimage import feature

class HOG:
    def __init__(self ,
     orientations = 9, 
    pixelPerCell = ( 8 ,8 ) ,
    cellsPerBlock = (3,3) , 
    transform = False):
    # 存储方向数字,每个单元的方向数
    # 每个单元块，并且无论是否有 幂率
    # 应该应用压缩
        self.orientations = orientations
        self.pixelPerCell = pixelPerCell
        self.cellsPerBlock = cellsPerBlock
        self.transform = transform
    

    def describe(self , image):
        # j计算手写的数字图像
		hist = feature.hog(image, orientations = self.orienations,
			pixels_per_cell = self.pixelsPerCell,
			cells_per_block = self.cellsPerBlock,
			transform_sqrt = self.transform)

        return hist


        
