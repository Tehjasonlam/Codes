# Clustering Analysis Project

**Author:** Tri Lam  
**ID:** 1916079  

## Project Description
This project performs clustering analysis on a dataset of patient clinical records using K-Means and DBSCAN algorithms. The results are evaluated in terms of purity and silhouette coefficients. The project includes code implementations for the clustering algorithms, evaluation functions, and a detailed report of the findings.

---

## Files Included
1. **clustering.ipynb**  
   The Jupyter Notebook containing all the code for implementing the clustering analysis tasks, including:
   - Task 1: Compute Purity
   - Task 2: K-Means with k=2
   - Task 3: K-Means with varying k values
   - Task 4: DBSCAN with varying epsilon values

2. **clinical_records_dataset.csv**  
   The dataset of patient clinical records used for clustering analysis. It contains 299 records with 13 attributes.

3. **README.md**  
   This file describes the project, files included, and steps to run the code.

4. **report.pdf**  
   A detailed report summarizing the objectives, methods, results, and conclusions for each task.

---

## Dependencies
To run the code, the following Python libraries are required:
- numpy
- pandas
- scikit-learn
- collections (built-in)

---

## How to Run the Code
1. **Ensure the dataset is in the same directory as the notebook**:  
   - File: `clinical_records_dataset.csv`

2. **Open the notebook**:  
   Use Jupyter Notebook or JupyterLab to open `clustering.ipynb`.

3. **Run the code**:  
   - Execute each cell sequentially to generate the results for all tasks.
   - The notebook contains outputs for each task, including figures and evaluation metrics.

4. **Tasks and Results**:  
   - **Task 1**: Purity computation for clustering.
   - **Task 2**: K-Means clustering with k=2, including overall purity and cluster percentages.
   - **Task 3**: K-Means clustering with varying k values (2, 10, 30, 50, 100), including purity and silhouette coefficients.
   - **Task 4**: DBSCAN with varying epsilon values (0.3, 0.5, 0.7), including cluster counts, anomalies, and purity.

5. **Report**:  
   Refer to `report.pdf` for a detailed summary of the project’s findings and conclusions.

---

## Expected Outputs
### Task 1
- Computes purity for a sample clustering scenario.
- Output text example:  .75

### Task 2
- K-Means with k=2:
- Overall purity.
- Cluster-wise purity and percentages.

### Task 3
- K-Means with varying k:
- Average purity and silhouette coefficients for k = 2, 10, 30, 50, 100.
- Output table summarizing metrics.

### Task 4
- DBSCAN with varying epsilon values:
- Number of clusters, anomalies, and purity.
- Output table summarizing metrics.

---


