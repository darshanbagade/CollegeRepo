# Import libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
# Load dataset from sklearn
from sklearn.datasets import load_iris
iris = load_iris()
# Convert to DataFrame
df = pd.DataFrame(iris.data, columns=iris.feature_names)
df['target'] = iris.target
# Show first 5 rows
df.head()
# Dataset shape
print("Shape of dataset:", df.shape)
# Dataset info
df.info()
# Statistical summary
df.describe()
sns.pairplot(df, hue='target')
plt.show()
plt.figure(figsize=(8,6))
sns.heatmap(df.corr(), annot=True, cmap='coolwarm')
plt.title("Correlation Matrix")
plt.show()
df.hist(figsize=(8,6))
plt.tight_layout()
plt.show()
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, classification_report
# Features and target
X = df.drop('target', axis=1)
y = df['target']
# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)
# Create KNN model (k=3)
knn = KNeighborsClassifier(n_neighbors=3)
# Train model
knn.fit(X_train, y_train)
# Predictions
y_pred = knn.predict(X_test)
# Accuracy
print("Accuracy:", accuracy_score(y_test, y_pred))
# Detailed report
print(classification_report(y_test, y_pred))
accuracy_list = []
for k in range(1, 21):
    model = KNeighborsClassifier(n_neighbors=k)
    model.fit(X_train, y_train)
    pred = model.predict(X_test)
    accuracy_list.append(accuracy_score(y_test, pred))
# Plot accuracy vs k
plt.plot(range(1,21), accuracy_list, marker='o')
plt.xlabel("Value of K")
plt.ylabel("Accuracy")
plt.title("K vs Accuracy")
plt.show()