#stop all container
docker stop $(docker ps -aq)

#remove all container
docker rm -f $(docker ps -aq)

#remove all images
docker rmi -f $(docker images -q)

docker system prune