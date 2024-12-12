Bean Variety Classification
This project classifies different types of beans using machine learning models: Decision Tree, K-Nearest Neighbors (K-NN), Support Vector Machine (SVM), and Gradient Boosting Classifier.

Files
classification.ipynb: The main code file with all tasks.
Dry_Bean_Dataset.csv: Dataset used for training and testing the models.
report.pdf: A detailed report with explanations, analysis, and results for each task.
Requirements
You’ll need the following libraries:

pandas
scikit-learn
numpy
matplotlib
Install them by running:

bash
Copy code
pip install pandas scikit-learn numpy matplotlib
Running the Code in VS Code
Open the Project:

Open classification.ipynb in VS Code.
Ensure Dry_Bean_Dataset.csv is in the same directory.
Set Up Jupyter in VS Code:

Install the Jupyter extension in VS Code if it’s not already installed.
Open classification.ipynb to start the Jupyter environment.
Run Each Cell:

Run each cell in order to complete:
Task 1: Decision Tree model
Task 2: K-NN model
Task 3: SVM model
Task 4: Gradient Boosting model
Task 5: Model comparison
View Results:

Each task displays evaluation metrics.
Task 5 outputs a final comparison table showing the best-performing model.
Report
Refer to report.pdf for a detailed analysis of each model, including explanations of model parameters, performance metrics, and the final conclusions.

Summary
The project uses cross-validation to evaluate each model. The final table in Task 5 compares models based on accuracy, precision, recall, and F1 scores, helping to identify the best model for bean classification.