pipeline {
agent any

environment {
    DOCKER_IMAGE = 'shavari2006/plagiarism-detection'
}
stages {
    stage('Checkout') {
        steps {
            git branch: 'main',
                url: 'https://github.com/Shavari-kd/plagiarism-detection-system.git'
        }
    }
    stage('Build and Test C++') {
        steps {
            sh '''
                g++ main.cpp lcs.cpp similarity.cpp utils.cpp -o plagiarism
                echo "Plagiarism Detection System compiled successfully"
            '''
        }
    }
    stage('Build Docker Image') {
        steps {
            sh 'docker build -t ${DOCKER_IMAGE}:latest .'
        }
    }
    stage('Login and Push to Docker Hub') {
        steps {
            withCredentials([usernamePassword(
                credentialsId: 'dockerhub-creds',
                usernameVariable: 'DOCKER_USER',
                passwordVariable: 'DOCKER_PASS'
            )]) {
                sh '''
                    echo "$DOCKER_PASS" | docker login -u "$DOCKER_USER" --password-stdin
                    docker push ${DOCKER_IMAGE}:latest
                    docker logout
                '''
            }
        }
    }
    stage('Deploy to Kubernetes') {
        steps {
            sh '''
                kubectl apply -f k8s/deployment.yaml
                kubectl apply -f k8s/service.yaml
                kubectl rollout status deployment/plagiarism-detection
            '''
        }
    }
    stage('Verify Deployment') {
        steps {
            sh '''
                kubectl get pods
                kubectl get deployments
                kubectl get services
            '''
        }
    }
}

}