#!/bin/sh

git add .
echo "comment is"
read comment
git commit -m "$comment"
git push
