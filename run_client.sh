FILES=./test_cases/*
for f in $FILES
do
  echo "Processing $f"
  # take action on each file. $f store current file name
  cp $f ./urls.txt
  ./client
done
