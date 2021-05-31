killall kubectl

# Kubernetes v1.14.2, ARP mode must be enabled (as specified by https://metallb.universe.tf/installation/): with these commands, the activation of this mode is automated
kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl diff -f - -n kube-system

kubectl get configmap kube-proxy -n kube-system -o yaml | \
sed -e "s/strictARP: false/strictARP: true/" | \
kubectl apply -f - -n kube-system

# Install MetalLB through manifest
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

# Build docker images
docker build -t nginx ./srcs/nginx/
docker build -t wordpress ./srcs/wp/
docker build -t phpmyadmin ./srcs/phpmyadmin/
docker build -t grafana ./srcs/grafana/
docker build -t influxdb ./srcs/influxDB/
docker build -t ftps ./srcs/ftps/
docker build -t mysql ./srcs/mysql/

# Start K8s pods
kubectl apply -f ./srcs/kubernetes/metalLB.yaml
kubectl apply -f ./srcs/kubernetes/mysql-persistent-volume.yaml
kubectl apply -f ./srcs/kubernetes/mysql.yaml
kubectl apply -f ./srcs/kubernetes/nginx.yaml
kubectl apply -f ./srcs/kubernetes/wp-persistent-volume.yaml
kubectl apply -f ./srcs/kubernetes/wp.yaml
kubectl apply -f ./srcs/kubernetes/phpmyadmin.yaml
kubectl apply -f ./srcs/kubernetes/ftps.yaml
kubectl apply -f ./srcs/kubernetes/grafana-persistent-volume.yaml
kubectl apply -f ./srcs/kubernetes/grafana.yaml
kubectl apply -f ./srcs/kubernetes/influxdb-persistent-volume.yaml
kubectl apply -f ./srcs/kubernetes/influxdb.yaml

# K8s dashboard configuration
kubectl apply -f https://raw.githubusercontent.com/kubernetes/dashboard/v2.0.0/aio/deploy/recommended.yaml
cat <<EOF | kubectl apply -f -
apiVersion: v1
kind: ServiceAccount
metadata:
  name: admin-user
  namespace: kubernetes-dashboard
EOF
cat <<EOF | kubectl apply -f -
apiVersion: rbac.authorization.k8s.io/v1
kind: ClusterRoleBinding
metadata:
  name: admin-user
roleRef:
  apiGroup: rbac.authorization.k8s.io
  kind: ClusterRole
  name: cluster-admin
subjects:
- kind: ServiceAccount
  name: admin-user
  namespace: kubernetes-dashboard
EOF
kubectl -n kubernetes-dashboard get secret $(kubectl -n kubernetes-dashboard get sa/admin-user -o jsonpath="{.secrets[0].name}") -o go-template="{{.data.token | base64decode}}" | pbcopy
kubectl proxy &
sleep 10s
open http://localhost:8001/api/v1/namespaces/kubernetes-dashboard/services/https:kubernetes-dashboard:/proxy/
