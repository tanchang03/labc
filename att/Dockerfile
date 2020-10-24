FROM alpine

WORKDIR /app
ADD ./* ./

RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.aliyun.com/g' /etc/apk/repositories
ENV VERSION 2.14.02-r0

RUN apk add --no-cache nasm=${VERSION}  binutils\
  && rm -rf /var/cache/apk/*

