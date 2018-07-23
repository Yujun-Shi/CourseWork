import math

from scipy.sparse import csr_matrix
import numpy as np



class pageRanker:
    # according to the original paper, 
    # we denote Y_ as the initial vector
    # res stands for residule
    def __init__(self, alpha_, lap_, res_ = 1e-4):
        self.alpha = alpha_
        self.lap = lap_
        self.res = res_
    
    def rankRes(self):
        diagRow_ = np.arange(1+self.lap.shape[0])
        diagCol_ = np.arange(self.lap.shape[0])
        diagVal_ = np.ones(self.lap.shape[0])
        diag_ = csr_matrix((diagVal_, diagCol_, diagRow_),
                           shape=(self.lap.shape[0], self.lap.shape[1]),
                           dtype=np.float32)

        # all these operator should be carefully dig in!!!!
        print(diag_.shape)
        print(self.lap.shape)
        M = (1.0 - self.alpha)*diag_ + self.alpha*self.lap.transpose()
        res_ = math.inf
        Y = np.ones(self.lap.shape[0],dtype=np.float32)
        
        i = 0
        while(res_ > self.res):
            Y_ = M.dot(Y)
            diff = (Y_ - Y)
            res_ = diff.dot(diff)
            print("iteration: " + str(i) + " " + "residual: " + str(res_))
            Y = Y_
            i = i + 1
        return Y

