# -*- coding: utf-8 -*-
# @Author  :蕾姆233
# @Software: PyCharm
# 使用MovieLens数据集，它是在实现和测试推荐引擎时所使用的最常见的数据集之一。它包含来自于943个用户
# 以及精选的1682部电影的100K个电影打分。
import pandas as pd
import numpy as np
from sklearn.metrics.pairwise import pairwise_distances

# pass in column names for each CSV as the column name is not given in the file and read them using pandas.
# You can check the column names from the readme file

# Reading users file:
u_cols = ['user_id', 'age', 'sex', 'occupation', 'zip_code']
users = pd.read_csv('ml-100k/u.user', sep='|', names=u_cols, encoding='latin-1')

# Reading ratings file:
r_cols = ['user_id', 'movie_id', 'rating', 'unix_timestamp']
ratings = pd.read_csv('ml-100k/u.data', sep='\t', names=r_cols, encoding='latin-1')

# Reading items file:
i_cols = ['movie id', 'movie title', 'release date', 'video release date', 'IMDb URL', 'unknown', 'Action', 'Adventure',
          'Animation', 'Children\'s', 'Comedy', 'Crime', 'Documentary', 'Drama', 'Fantasy',
          'Film-Noir', 'Horror', 'Musical', 'Mystery', 'Romance', 'Sci-Fi', 'Thriller', 'War', 'Western']
items = pd.read_csv('ml-100k/u.item', sep='|', names=i_cols, encoding='latin-1')


r_cols = ['user_id', 'movie_id', 'rating', 'unix_timestamp']
ratings_train = pd.read_csv('ml-100k/ua.base', sep='\t', names=r_cols, encoding='latin-1')
ratings_test = pd.read_csv('ml-100k/ua.test', sep='\t', names=r_cols, encoding='latin-1')
print("Train Set Shape: ", ratings_train.shape, "\n", "Test Set Shape: ", ratings_test.shape)

# user-user sim
n_users = ratings.user_id.unique().shape[0]
n_items = ratings.movie_id.unique().shape[0]
data_matrix = np.zeros((n_users, n_items))
for line in ratings.itertuples():
    data_matrix[line[1] - 1, line[2] - 1] = line[3]

print(data_matrix.shape)

user_similarity = pairwise_distances(data_matrix, metric='cosine')
item_similarity = pairwise_distances(data_matrix.T, metric='cosine')


# This gives us the item-item and user-user similarity in an array form. The next step is to make predictions based on these similarities.
#  Let’s define a function to do just that.
def predict(ratings, similarity, type='user'):
    # ratings 用户电影矩阵，值为评分。
    if type == 'user':
        # 按行计算的均值 横向执行对应的方法
        mean_user_rating = ratings.mean(axis=1)  # 943个用户对电影打分的均值。
        ratings_diff = (ratings - mean_user_rating[:, np.newaxis])  # 减去均值
        pred = mean_user_rating[:, np.newaxis] + similarity.dot(ratings_diff) / np.array(
            [np.abs(similarity).sum(axis=1)]).T
    elif type == 'item':
        # similarity 电影和电影的相似度矩阵。
        pred = ratings.dot(similarity) / np.array([np.abs(similarity).sum(axis=1)])
    return pred


user_prediction = predict(data_matrix, user_similarity, type='user')
item_prediction = predict(data_matrix, item_similarity, type='item')
print(user_prediction.shape)
print(user_prediction)
print(item_prediction.shape)
print(item_prediction)