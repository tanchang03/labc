FROM alpine:3.12
WORKDIR /app
ADD ./src ./
# ENTRYPOINT ["/bin/sh"]

ENV VERSION 2.14.02-r0

RUN sed -i 's/dl-cdn.alpinelinux.org/mirrors.aliyun.com/g' /etc/apk/repositories
# Install qemu
RUN apk add --no-cache nasm=${VERSION}  binutils\
  && rm -rf /var/cache/apk/*

# ENTRYPOINT ["/usr/bin/nasm"]
# CMD ["-h"]
