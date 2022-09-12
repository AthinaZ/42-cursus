#!/bin/bash
web_image=$(docker images | grep web | wc -l)
echo $web_image

if [[ $web_image != 0 ]]
then
	docker build . -t web-server
	docker run --name webserver --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 8000:8000 -p 8080:8080 -v $(pwd):/home/app/webserv -it web-server  bash
fi

