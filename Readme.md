Plagiarism Detection System

1. Project Overview

The Plagiarism Detection System is an academic project designed to identify similarities between two text documents.

The project uses the Longest Common Subsequence (LCS) algorithm and Dynamic Programming to calculate text similarity. It also includes a web interface for interacting with the plagiarism detection system.

This project was selected for CCA 2 to demonstrate the implementation of a CI/CD pipeline using Jenkins, Docker, Docker Hub, and Kubernetes.



2. Objectives

* Develop a plagiarism detection system using the LCS algorithm.
* Calculate similarity between two text inputs.
* Store the source code in a GitHub repository.
* Automate compilation and deployment using Jenkins.
* Package the web interface into a Docker image.
* Publish the Docker image to Docker Hub.
* Deploy the application using Kubernetes on Minikube.



3. Technologies Used

Technology	               Purpose
C++	                       Implements the LCS algorithm and similarity calculation
HTML, CSS, JavaScript	   Web interface
Git and GitHub	           Source code management
AWS EC2	                   Hosts the Jenkins server and deployment environment
Jenkins	                   Automates the CI/CD pipeline
Docker	                   Builds the application container image
Docker Hub	               Stores the Docker image
Kubernetes	               Manages application deployment
Minikube	               Provides the local Kubernetes cluster
kubectl	                   Manages and verifies Kubernetes resources
Nginx	                   Serves the web interface from the container



4. Project Structure

plagiarism-detection-system/
│
├── main.cpp
├── lcs.cpp
├── lcs.h
├── similarity.cpp
├── similarity.h
├── utils.cpp
├── utils.h
├── plagiarism_detector.html
├── Dockerfile
├── Jenkinsfile
├── README.md
│
└── k8s/
    ├── deployment.yaml
    └── service.yaml



5. CI/CD Pipeline

The Jenkins pipeline automates the process of building and deploying the project.

Stage 1: Checkout

Jenkins downloads the latest source code from the GitHub repository.


Stage 2: Build and Test C++

The C++ source files are compiled using the GNU C++ compiler.

The compilation command is:

g++ main.cpp lcs.cpp similarity.cpp utils.cpp -o plagiarism

Successful compilation verifies that the C++ source files build correctly.


Stage 3: Build Docker Image

Jenkins builds a Docker image using the Dockerfile.

The image packages the web interface using Nginx.


Stage 4: Push Image to Docker Hub

Jenkins authenticates with Docker Hub using credentials stored in Jenkins Credentials.

The image is published to:

shavari2006/plagiarism-detection:latest


Stage 5: Deploy to Kubernetes

Jenkins applies the Kubernetes Deployment and Service manifests.

The Deployment manages the application pod, while the Service exposes the application inside the Kubernetes environment.


Stage 6: Verify Deployment

Jenkins checks the deployment rollout and verifies the Kubernetes pods, deployment, and services.



6. Docker Configuration

The Dockerfile uses the lightweight Nginx Alpine image.

FROM nginx:alpine
COPY plagiarism_detector.html /usr/share/nginx/html/index.html
EXPOSE 80

The HTML interface is served by Nginx inside the Docker container.



7. Kubernetes Deployment

The project uses two Kubernetes manifest files:

* k8s/deployment.yaml — defines the application Deployment and container image.
* k8s/service.yaml — exposes the application through a NodePort Service.

The application is deployed on Minikube.

The Kubernetes Service uses NodePort 30080 and forwards traffic to container port 80.



8. AWS and Jenkins Setup

An AWS EC2 instance was configured to host Jenkins and the tools required for the CI/CD pipeline.

The environment includes:

* Jenkins
* Git
* GNU C++ compiler
* Docker
* kubectl
* Minikube

Jenkins was configured with the necessary Docker permissions, Kubernetes access, and Docker Hub credentials.

A Jenkins Pipeline job was connected to the GitHub repository and configured to execute the Jenkinsfile.



9. Deployment Verification

The following commands were used to verify the Kubernetes deployment:

kubectl get pods
kubectl get deployments
kubectl get services

Successful verification showed:

* The application pod in the Running state.
* One available replica in the Deployment.
* The plagiarism detection Service configured as a NodePort.

The application was accessed through a browser after configuring port forwarding from the EC2 environment.



10. Second Code Change and Redeployment

After the initial successful pipeline execution, the website source code was modified to make the application version more visible.

The update introduced a Version 2.0 release banner and updated the engine version label.

The modified file was committed and pushed to GitHub.

Jenkins was then executed again to:

1. Retrieve the updated source code.
2. Compile the C++ source files.
3. Build a new Docker image.
4. Push the updated image to Docker Hub.
5. Apply the Kubernetes deployment configuration.
6. Verify the deployment.

The second pipeline execution completed successfully, demonstrating the source-code change and redeployment workflow.



11. Conclusion

This project demonstrates how an existing academic software project can be integrated with a CI/CD pipeline.

Jenkins automates source code checkout, compilation, Docker image creation, image publishing, and Kubernetes deployment.

Docker provides application containerization, Docker Hub stores the image, and Kubernetes manages the deployed application.

The successful initial deployment and subsequent source-code update demonstrate the main CI/CD workflow required for the CCA 2 project.