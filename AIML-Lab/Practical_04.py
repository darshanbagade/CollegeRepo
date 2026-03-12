from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, MinMaxScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score

# Load dataset
data = load_iris()
X = data.data
y = data.target

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Model
model = LogisticRegression(max_iter=200)

# Without preprocessing
model.fit(X_train, y_train)
y_pred = model.predict(X_test)

print("Without Preprocessing")
print("Accuracy:", accuracy_score(y_test, y_pred))
print("Precision:", precision_score(y_test, y_pred, average='macro'))
print("Recall:", recall_score(y_test, y_pred, average='macro'))
print("F1 Score:", f1_score(y_test, y_pred, average='macro'))


# Standardization
scaler = StandardScaler()
X_train_std = scaler.fit_transform(X_train)
X_test_std = scaler.transform(X_test)

model.fit(X_train_std, y_train)
y_pred_std = model.predict(X_test_std)

print("\nWith Standardization")
print("Accuracy:", accuracy_score(y_test, y_pred_std))
print("Precision:", precision_score(y_test, y_pred_std, average='macro'))
print("Recall:", recall_score(y_test, y_pred_std, average='macro'))
print("F1 Score:", f1_score(y_test, y_pred_std, average='macro'))

# Normalization
normalizer = MinMaxScaler()
X_train_norm = normalizer.fit_transform(X_train)
X_test_norm = normalizer.transform(X_test)

model.fit(X_train_norm, y_train)
y_pred_norm = model.predict(X_test_norm)

print("\nWith Normalization")
print("Accuracy:", accuracy_score(y_test, y_pred_norm))
print("Precision:", precision_score(y_test, y_pred_norm, average='macro'))
print("Recall:", recall_score(y_test, y_pred_norm, average='macro'))
print("F1 Score:", f1_score(y_test, y_pred_norm, average='macro'))
