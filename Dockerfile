FROM nginx:alpine

COPY plagiarism_detector.html /usr/share/nginx/html/index.html

EXPOSE 80