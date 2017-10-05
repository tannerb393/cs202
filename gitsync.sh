#!/bin/bash
NOW=$(date +"%m-%d-%Y-%H:%M")

git add .
git commit -m "$NOW"
git push origin

