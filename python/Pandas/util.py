import pandas as pd
#对于离散值不能进行编码的利用onehot编码
df = pd.DataFrame([
    ['green', 'M', 10.1, 'class1'],
    ['red', 'L', 13.5, 'class2'],
    ['blue', 'XL', 15.3, 'class1']])

df.columns = ['color', 'size', 'prize', 'class label']

size_mapping = {
    'XL': 3,
    'L': 2,
    'M': 1}
df['size'] = df['size'].map(size_mapping)

class_mapping = {label: idx for idx, label in enumerate(set(df['class label']))}
df['class label'] = df['class label'].map(class_mapping)
print('----------------------------------------------------------------')

print(df)

print('----------------------------------------------------------------')
df = pd.get_dummies(df)
print(df)
print('----------------------------------------------------------------')
