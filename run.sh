DAY=$1 
PART=$2
SAMPLE=$3

if [ -n "${SAMPLE}" ]; then
  bin/aoc -d ${DAY} -p ${PART} -f data/sample/test_cases/day${DAY}_test1.txt 
elif  [ "${PART}" == "ALL" ]; then
  bin/aoc -d ${DAY} -p 1 -f data/sample/test_cases/day${DAY}_test1.txt 
  bin/aoc -d ${DAY} -p 1 -f data/sample/day${DAY}_input.txt
  bin/aoc -d ${DAY} -p 2 -f data/sample/test_cases/day${DAY}_test1.txt 
  bin/aoc -d ${DAY} -p 2 -f data/sample/day${DAY}_input.txt
elif  [ -n "${PART}" ]; then
  bin/aoc -d ${DAY} -p ${PART} -f data/sample/day${DAY}_input.txt
else
  bin/aoc -d ${DAY} -p 1 -f data/sample/day${DAY}_input.txt
  bin/aoc -d ${DAY} -p 2 -f data/sample/day${DAY}_input.txt
fi
