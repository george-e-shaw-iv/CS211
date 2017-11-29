#!/bin/bash

LINE=0
SPACES=0
HASHES=0

while [ $LINE -lt 4 ]; do
  let SPACES=LINE

  while [ $SPACES -gt 0 ]; do
    echo -ne " "
    let SPACES=SPACES-1
  done

  let HASHES="8-(LINE*2)"
  while [ $HASHES -gt 0 ]; do
    echo -ne "#"
    let HASHES=HASHES-1
  done

  echo -ne "\n"

  let LINE=LINE+1
done

echo -ne "\n\n"

LINE=0
SPACES=0
HASHES=0

while [ $LINE -lt 7 ]; do
  let SPACES=LINE-3

  if [ $SPACES -lt 0 ]
  then
    let SPACES="SPACES*-1"
  fi

  while [ $SPACES -gt 0 ]; do
    echo -ne " "
    let SPACES=SPACES-1
  done

  if [ $LINE -gt 3 ]
  then
    let HASHES=LINE-6
    if [ $HASHES -lt 0 ]
    then
      let HASHES="HASHES*-1"
    fi
    let HASHES="(HASHES*2)+2"
  else
    let HASHES="2+(LINE*2)"
  fi

  while [ $HASHES -gt 0 ]; do
    echo -ne "#"
    let HASHES=HASHES-1
  done

  echo -ne "\n"

  let LINE=LINE+1
done

echo -ne "\n\n"

LINE=0

while [ $LINE -lt 7 ]; do
  let HASHES=0

  while [ $HASHES -lt 7 ]; do
    if [ $LINE -eq $HASHES ] || [ $((6-$LINE)) -eq $HASHES ]
    then
      echo -ne "#"
    else
      echo -ne " "
    fi

    let HASHES=HASHES+1
  done

  echo -ne "\n"

  let LINE=LINE+1
done
