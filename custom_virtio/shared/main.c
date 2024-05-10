#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct virtio_rpc_ioctl_req {
  void *inbuf;
  size_t insize;

  void *outbuf;
  size_t outsize;
};

int main() {
  int fd = open("/dev/virtio_rpc0", O_RDWR);
  printf("Opened virtio rpc device %d\n", fd);

  struct virtio_rpc_ioctl_req req;

  char inp[] = "Hello world!!!";
  req.inbuf = inp;
  req.insize = sizeof(inp);

  char out[100];
  req.outbuf = out;
  req.outsize = sizeof(out);

  printf("Submitting request: %s\n", inp);

  int ret = ioctl(fd, 0, &req);
  printf("Executed ioctl %d\n", ret);

  printf("Recived response: %s\n", out);

  close(fd);
}