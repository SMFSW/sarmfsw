#!/bin/sh

# before first commit, set the script as executable to git:
# git update-index --chmod=+x .cppcheck/cppcheck.sh

exec cppcheck \
  --enable=warning,style,performance \
  --inconclusive \
  --inline-suppr \
  --force \
  --check-level=exhaustive \
  --suppress=missingIncludeSystem \
  --suppressions-list=./.cppcheck/cppcheck.suppress \
  --error-exitcode=1 \
  --platform=arm32-wchar_t2 \
  '-D__cppcheck__' \
  '-D__GNUC__' \
  '-DNONNULLX__(...)=""' \
  '-DSECTION__(...)=""' \
  '-D__SIZEOF_INT__=4' \
  '-D__SIZEOF_POINTER__=4' \
  .