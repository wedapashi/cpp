#!/bin/bash
for d in */; do # only match directories
  ( cd "$d" && make ) # Use a subshell to avoid having to cd back to the root each time.
done
