# Copyright 2016 The Fuchsia Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_TYPE := userapp

MODULE_SRCS += \
    $(LOCAL_DIR)/crashlogger.cpp \
    $(LOCAL_DIR)/backtrace.c \

MODULE_NAME := crashlogger

# This is needed only for hexdump8_ex, which ought to live somewhere else.
MODULE_STATIC_LIBS := ulib/ddk

MODULE_LIBS := \
    ulib/mxio ulib/magenta ulib/musl

include make/module.mk
