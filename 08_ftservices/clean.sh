kubectl delete -f srcs/kubernetes/metalLB.yaml
kubectl delete -f srcs/kubernetes/mysql.yaml
kubectl delete -f srcs/kubernetes/nginx.yaml
kubectl delete -f srcs/kubernetes/phpmyadmin.yaml
kubectl delete -f srcs/kubernetes/wp.yaml
kubectl delete -f srcs/kubernetes/ftps.yaml
kubectl delete -f srcs/kubernetes/influxdb.yaml
kubectl delete -f srcs/kubernetes/grafana.yaml
kubectl delete -f srcs/kubernetes/grafana-persistent-volume.yaml
kubectl delete -f srcs/kubernetes/influxdb-persistent-volume.yaml
kubectl delete -f srcs/kubernetes/mysql-persistent-volume.yaml
kubectl delete -f srcs/kubernetes/wp-persistent-volume.yaml

kubectl delete --all deployments
kubectl delete --all pods
kubectl delete --all services
kubectl delete --all pvc

#stop all container
docker stop $(docker ps -aq)

#remove all container
docker rm -f $(docker ps -aq)

#remove all images
docker rmi -f $(docker images -q)

docker system prune
