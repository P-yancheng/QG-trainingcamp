from keras.datasets import boston_housing
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error,mean_absolute_error,r2_score
from matplotlib import pyplot
from sklearn.preprocessing import StandardScaler
import numpy as np

#1. load data
(X_train, y_train), (X_test, y_test) = boston_housing.load_data(test_split=0.1)

#2. preprocess data
#pyplot.plot(X_train)
#pyplot.show()

ss_X = StandardScaler()
X_train = ss_X.fit_transform(X_train)
X_test = ss_X.transform(X_test)

#pyplot.plot(X_train)
#pyplot.show()

ss_y = StandardScaler()
y_train = ss_y.fit_transform(y_train.reshape(-1,1))
y_test = ss_y.transform(y_test.reshape(-1,1))

#3. model train
# model = LinearRegression()
# model.fit(X_train,y_train)

dimension = 13 + 1
w = np.zeros([dimension,1])
X_train = np.concatenate((np.ones([len(X_train),1]), X_train), axis = 1).astype(float)
learning_rate: float = 0.0001
iter_time = 100

losslist = []
for t in range(iter_time):
    loss = np.sqrt(np.sum(np.power(np.dot(X_train, w) - y_train, 2))/len(X_train))#rmse
    losslist.append(loss)
    if(t%1==0):
        print(str(t) + ":" + str(loss))
    gradient = 2 * np.dot(X_train.transpose(), np.dot(X_train, w)-y_train) #dim*1
    w=w - learning_rate * grandient

# 
