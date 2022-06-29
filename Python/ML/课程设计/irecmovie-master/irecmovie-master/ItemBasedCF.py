import math
import random
import pprint


# 加载数据
def loadData(filename):
    """
    加载数据集
    """
    data = []
    for line in open(filename):
        user, item, record, timestamp = line.split()
        data.append((user, item, int(record)))
    return data


# 随机切分数据集为训练集和测试集
def splitData(data, M, K, seed):
    """
    随机切分数据集 训练集 和 测试集
    """
    test = {}   # 字典
    train = {}
    random.seed(seed)
    for user, item, record in data:
        if random.randint(0, M) <= K:
            test.setdefault(user, {})
            test[user][item] = record
        else:
            train.setdefault(user, {})
            train[user][item] = record
    return train, test


# 计算算法的精度和回调
def precisionAndRecall(train, test, W, K, N):
    """
    计算算法的精度和回调
    """
    hit = 0;
    pre = 0;
    rec = 0
    for user in train.keys():
        tu = test.get(user, {})
        rank = recommender(user, train, W, K, N)
        for item, pui in rank.items():
            if item in tu:
                hit += 1
        pre += N
        rec += len(tu)
    return hit / (pre * 1.0), hit / (rec * 1.0)


# 覆盖率
def Coverage(train, test, W, K=3, N=10):
    train = train
    recommend_items = set()
    all_items = set()
    for user, items in train.items():
        for i in items.keys():
            all_items.add(i)
        rank = recommender(user, train, W, K, N)
        for i, _ in rank.items():
            recommend_items.add(i)
    return len(recommend_items) / (len(all_items) * 1.0)


def Popularity(train, test, W, K=3, N=10):
    item_popularity = dict()
    # 计算物品流行度
    for user, items in train.items():
        for i in items.keys():
            item_popularity.setdefault(i, 0)
            item_popularity[i] += 1
    ret = 0  # 新颖度结果
    n = 0  # 推荐的总个数
    for user in train.keys():
        rank = recommender(user, train, W, K=K, N=N)  # 获得推荐结果
        for item, _ in rank.items():
            ret += math.log(1 + item_popularity[item])
            n += 1
    ret /= n * 1.0
    return ret


# 物品相似度
def itemSimilarity(train, method='IUF'):     # IUF 增添一个制约项
    """
        计算物品之间的余弦相似度
    """
    C = {}
    N = {}
    for u, items in train.items():
        for i in items:
            N[i] = N.get(i, 0) + 1
            for j in items:
                if i == j: continue
                C.setdefault(i, {})
                if method == 'IUF':
                    C[i][j] = C[i].get(j, 0) + 1 / math.log(1 + len(items) * 1.0)
                else:
                    C[i][j] = C[i].get(j, 0) + 1
    W = {}
    for i, related_items in C.items():
        for j, cij in related_items.items():
            W.setdefault(i, {})
            W[i][j] = cij / math.sqrt(N[i] * N[j])
    return W


# 推荐
def recommender(user, train, W, K, N):
    """recommend to user N item according to K max similarity item
        给用户推荐N个物品，物品来源于与用户偏好物品的K个最相似的物品
    """
    rank = {}
    interacted_items = train[user]
    for i, pi in interacted_items.items():
        for j,  wj in sorted(W[i].items(), key=lambda c: c[1], reverse=True)[0:K]:
            if j in interacted_items:
                continue
            rank[j] = rank.get(j, 0) + pi * wj
    return dict(sorted(rank.items(), key=lambda c: c[1], reverse=True)[0:N])


# 测试算法各个指标
def testItemCF(filename):
    """
        测试算法在不同K值下的指标(pre rec cov pop)
    """
    data = loadData(filename)  # 读数据
    train, test = splitData(data, 9, 1, 2)
    W = itemSimilarity(train, method='IUF')

    # 打开文件,清空内容
    result = open('result_ibcf.data', 'w')

    print(u'不同K值下推荐算法的各项指标(精度、召回率、覆盖率、流行度)\n')
    print('K\t\tprecision\trecall\t\tCoverage\tPopularity')

    for k in [5, 10, 20, 40, 80, 160]:
        pre, rec = precisionAndRecall(train, test, W, k, 10)  # 算pre rec 准确率 召回率
        cov = Coverage(train, test, W, k, 10)  # 算cov 覆盖率
        pop = Popularity(train, test, W, k, 10)  # 算pop 流行度
        print("%3d\t\t%.2f%%\t\t%.2f%%\t\t%.2f%%\t\t%.6f" % (
        k, pre * 100, rec * 100, cov * 100, pop))  # 输出pre rec cov pop
        result.write(str(k) + ' ' + str('%2.2f' % (pre * 100)) + ' ' + str('%2.2f' % (rec * 100)) + ' ' + str(
            '%2.2f' % (cov * 100)) + ' ' + str('%2.6f' % pop) + '\n')  # 写入result


# 测试推荐算法
def testRecommend(filename):
    """
    测试推荐
    """
    data = loadData(filename)
    train, test = splitData(data, 9, 1, 2)
    W = itemSimilarity(train, method='IUF')
    rank = recommender('344', train, W, 10, 3)  # rank是推荐的电影 3部电影
    print(u'给id为344的用户推荐3部电影：')
    pprint.pprint(rank)


if __name__ == '__main__':
    # testRecommend('u.data')
    testItemCF('u.data')
