#!/bin/sh

setup_git() {
  git config --global user.email "travis@travis-ci.org"
  git config --global user.name "Travis CI"
}

commit_files() {
  git checkout test_branch
  git add -f build/bin/output.csv
  git commit --message "results"
}

upload_files() {
  git push origin HEAD
}

setup_git
commit_files
upload_files