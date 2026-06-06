# AI Engineering Portfolio — William Nepote

A collection of 11 hands-on projects built across the full AI Engineering curriculum, spanning classical programming, machine learning, deep learning, MLOps, computer vision, reinforcement learning, generative AI, and explainable AI.

---

## Projects

| # | Project | Topic | Stack |
|---|---------|-------|-------|
| 01 | [Contact Book CLI — Python OOP](#01-contact-book-python) | Python | Python, OOP, JSON |
| 02 | [InsuraPro CRM System — C++](#02-insurance-crm-cpp) | C++ | C++, OOP, File I/O |
| 03 | [Real Estate Price Prediction](#03-real-estate-price-prediction) | Machine Learning | scikit-learn, pandas, GridSearchCV |
| 04 | [Exotic Fruit Classifier](#04-exotic-fruit-classifier) | Machine Learning | scikit-learn, KNN, SVM |
| 05 | [Brand Reputation Monitoring](#05-brand-reputation-monitoring) | MLOps | FastAPI, Docker, MLflow, Prometheus |
| 06 | [Animal Detection for Autonomous Driving](#06-autonomous-driving-animal-detection) | Deep Learning | TensorFlow, Keras, CNN, CIFAR-10 |
| 07 | [Neural Network Optimization — Food Sector](#07-food-industry-nn-optimization) | PyTorch | PyTorch, Transfer Learning, Albumentations |
| 08 | [Flower Recognition for AgriTech](#08-agritech-flower-recognition) | Computer Vision | PyTorch, TIMM, GradCAM, YOLO |
| 09 | [Healthcare Cybersecurity via RL](#09-healthcare-cybersecurity-rl) | Reinforcement Learning | SARSA, DDQN, gym-idsgame |
| 10 | [Data Augmentation for Power Plant Security](#10-power-plant-data-augmentation) | Generative AI | BLIP, Flan-T5, FLUX, ResNet18 |
| 11 | [Banking Compliance with Explainable AI](#11-banking-compliance-xai) | Explainable AI | PyTorch, DenseNet, SHAP, LIME, Captum |

---

## 01 — Contact Book CLI — Python OOP

**Topic:** Python · Object-Oriented Programming

A command-line contact management application built with pure Python. Supports adding, viewing, editing, searching, and deleting contacts, with persistent JSON storage.

**Key concepts:** OOP class design, JSON serialization, input validation, CLI menu loop.

```
01-contact-book-python/
├── main.py
└── models.py
```

---

## 02 — InsuraPro CRM System — C++

**Topic:** C++ · Object-Oriented Programming

A fully featured CRM system for an insurance company, built in C++ with multi-file architecture. Manages client records and interaction histories with file-based persistence.

**Key concepts:** classes and objects, multiple/virtual inheritance, operator overloading, polymorphism, friend functions, file I/O.

```
02-insurance-crm-cpp/
├── main.cpp
├── CRMSystem.{h,cpp}
├── Client.{h,cpp}
├── Interaction.{h,cpp}
├── FileManager.{h,cpp}
└── data.txt
```

---

## 03 — Real Estate Price Prediction

**Topic:** Machine Learning · Regression

An end-to-end ML pipeline to predict housing prices. Covers exploratory data analysis, feature engineering, multiple regression algorithms, and hyperparameter tuning with GridSearchCV.

**Key concepts:** linear/polynomial regression, regularization (Ridge, Lasso), StandardScaler, OneHotEncoder, cross-validation, GridSearchCV.

**Stack:** `scikit-learn` · `pandas` · `numpy` · `matplotlib` · `seaborn`

```
03-real-estate-price-prediction/
├── HousingPricePredictionModel.ipynb
└── housing.csv
```

---

## 04 — Exotic Fruit Classifier

**Topic:** Machine Learning · Classification

A multi-class classification system to identify exotic fruit species from feature data. Benchmarks multiple algorithms and analyzes the bias-variance tradeoff via learning curves.

**Key concepts:** KNN, Naive Bayes, SVM (SVC), Mini-Batch/Online learning, confusion matrix, log-loss, learning curves.

**Stack:** `scikit-learn` · `pandas` · `numpy` · `matplotlib`

```
04-exotic-fruit-classifier/
├── Riconoscimento_frutti_esotici.ipynb
└── fruits.csv
```

---

## 05 — Brand Reputation Monitoring

**Topic:** MLOps · Model Serving · Monitoring

A production-ready MLOps pipeline for real-time social media sentiment analysis. Includes model training, REST API serving, containerization, and observability.

**Key concepts:** model serving with FastAPI, Docker containerization, experiment tracking with MLflow, monitoring with Prometheus/Grafana, unit testing.

**Stack:** `FastAPI` · `Docker` · `MLflow` · `Prometheus` · `scikit-learn` · `pytest`

```
05-brand-reputation-monitoring/
├── app/            # FastAPI service
├── training/       # Training pipeline
├── monitoring/     # Prometheus + Grafana config
├── tests/
├── Dockerfile
├── docker-compose.yml
└── requirements.txt
```

---

## 06 — Animal Detection for Autonomous Driving

**Topic:** Deep Learning · Convolutional Neural Networks

A CNN-based image classifier trained on CIFAR-10 to detect animals and objects for autonomous vehicle perception systems. Explores architecture design, transfer learning, and data augmentation.

**Key concepts:** CNN architecture, ImageDataGenerator, GlobalAveragePooling, callbacks, batch normalization, Transfer Learning with Keras.

**Stack:** `TensorFlow` · `Keras` · `numpy` · `matplotlib`

```
06-autonomous-driving-animal-detection/
└── Progetto guida autonoma CNN.ipynb
```

---

## 07 — Neural Network Optimization — Food Sector

**Topic:** PyTorch · Transfer Learning · Optimization

A transfer learning project for food image classification, with focus on maximizing validation accuracy through custom augmentation strategies and model optimization.

**Key concepts:** pretrained models (torchvision hub), Transfer Learning, custom augmentation with Albumentations, confusion matrix, reproducibility (seeding).

**Stack:** `PyTorch` · `torchvision` · `Albumentations` · `scikit-learn` · `seaborn`

```
07-food-industry-nn-optimization/
└── Esercitazione_Transfer_Learning_Pytorch.ipynb
```

---

## 08 — Flower Recognition for AgriTech

**Topic:** Computer Vision · TIMM · Explainability

A computer vision pipeline for GreenTech Solutions Ltd to classify Daisy vs Dandelion flowers. Covers full CV workflow from EDA to deployment-ready inference, with GradCAM-based visual explainability.

**Key concepts:** TIMM model zoo, GradCAM, YOLO, image preprocessing (OpenCV), Hooks for explainability, EDA on image datasets, F1-score, classification report.

**Stack:** `PyTorch` · `TIMM` · `Albumentations` · `OpenCV` · `Ultralytics YOLO` · `scikit-learn`

```
08-agritech-flower-recognition/
└── CV_project_GreenTech_Solutions_Ltd.ipynb
```

---

## 09 — Healthcare Cybersecurity via RL

**Topic:** Reinforcement Learning · Network Defense

An RL system to defend hospital networks against simulated cyberattacks. Implements and compares tabular and deep RL algorithms on the `gym-idsgame` intrusion detection environment.

**Key concepts:** SARSA with function approximation, DDQN with Experience Replay and Target Network, Q-Learning, PPO, Actor-Critic, value/policy iteration.

**Stack:** `gym-idsgame` · `NumPy` · `PyTorch` · `Google Colab`

```
09-healthcare-cybersecurity-rl/
└── Cybersecurity+_RL_Project.ipynb
```

---

## 10 — Data Augmentation for Power Plant Security

**Topic:** Generative AI · Diffusion Models · Vision

A generative data-augmentation pipeline for CyberEye Solutions to expand a small, imbalanced surveillance image dataset for critical infrastructure protection. The OxfordIIITPet dataset (37 cat/dog breeds) is used as a proxy for the real surveillance domain. The pipeline auto-captions each image (BLIP), paraphrases the captions with a text-generation model (Flan-T5), generates new synthetic images from the refined captions (FLUX.1-schnell), then measures the impact by training a ResNet18 classifier on the original vs. the augmented dataset.

**Key concepts:** image captioning (BLIP), text generation / caption paraphrasing (Flan-T5), text-to-image diffusion (FLUX.1-schnell), diffusion model theory, class-imbalance / weak-class targeting, transfer learning (ResNet18 pretrained on ImageNet), generative quality metrics (FID, KID, Inception Score), classification metrics (accuracy, precision, recall, F1).

**Result:** on the 10 weakest classes, the augmented model improved F1 by +18.9% and recall by +21.4% (global F1 +0.8%), with the quality/imbalance trade-off documented.

**Stack:** `Transformers (HuggingFace)` · `Diffusers` · `FLUX.1-schnell` · `Flan-T5` · `BLIP` · `PyTorch` · `OxfordIIITPet`

```
10-power-plant-data-augmentation/
└── Data_Augmentation_GenAI_Project.ipynb
```

---

## 11 — Banking Compliance with Explainable AI

**Topic:** Explainable AI · XAI · Regulatory Compliance

An XAI audit for Banca Virtuosa, applying multiple explainability techniques to a DenseNet121 model fine-tuned on MNIST (proxy for banking document classification). Ensures model decisions are transparent and compliant with regulatory standards.

**Key concepts:** Transfer Learning (DenseNet121 pretrained on ImageNet), Saliency Maps, GradCAM, LIME, SHAP, Captum library, confusion matrix analysis, top-K error pair selection for XAI targeting.

**Stack:** `PyTorch` · `torchvision` · `Captum` · `LIME` · `SHAP` · `matplotlib`

```
11-banking-compliance-xai/
└── XAI_Banking_Compliance.ipynb
```

---

## Skills Overview

```
Programming Languages    Python · C++
ML Frameworks            scikit-learn · PyTorch · TensorFlow/Keras
Computer Vision          OpenCV · TIMM · Albumentations · YOLO · GradCAM
Generative AI            HuggingFace Diffusers · FLUX · Flan-T5 · BLIP
Reinforcement Learning   SARSA · DQN · DDQN · PPO · Actor-Critic · gym-idsgame
Explainable AI           SHAP · LIME · Captum · Saliency Maps · GradCAM
MLOps                    FastAPI · Docker · MLflow · Prometheus · Grafana · pytest
```

---

## About

**William Nepote** — AI Engineering Graduate  
[LinkedIn](https://www.linkedin.com/in/william-nepote) · [GitHub](https://github.com/wil-nep)

> All projects were developed as part of a professional AI Engineering Master program covering the full stack from classical programming to production ML systems.
