#pragma once

#include <stdatomic.h>
#include <stdint.h>

#define NET_BUF 240
#define EV_BUF 64

enum sys_event {
  SYS_EVENT_NOOP,
  SYS_EVENT_CONNECTED,
  SYS_EVENT_DISCONNECTED,
};

struct socket_event {
  uint16_t client;
  uint16_t len;
  uint8_t read_buf[NET_BUF];
};

struct device_layout {
  atomic_uint_least16_t recieved;
  struct socket_event recv_evs[EV_BUF];
};
