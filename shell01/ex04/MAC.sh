#!/bin/sh
ifconfig -a link | grep ether | sed 's/[[:space:]]//g' | sed 's/ether//'
