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
# Pairplot
sns.pairplot(df, hue='target')
plt.show()
# Correlation heatmap
plt.figure(figsize=(8,6))
sns.heatmap(df.corr(), annot=True, cmap='coolwarm')
plt.title("Correlation Matrix")
plt.show()
# Histogram
df.hist(figsize=(8,6))
plt.tight_layout()
plt.show()
# ---------------------------
# Naive Bayes Classification
# ---------------------------
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import accuracy_score, classification_report
# Features and target
X = df.drop('target', axis=1)
y = df['target']
# Train-test split
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.3, random_state=42
)
# Create Naive Bayes model
nb = GaussianNB()
# Train model
nb.fit(X_train, y_train)
# Predictions
y_pred = nb.predict(X_test)
# Accuracy
print("Accuracy:", accuracy_score(y_test, y_pred))
# Detailed classification report
print(classification_report(y_test, y_pred))