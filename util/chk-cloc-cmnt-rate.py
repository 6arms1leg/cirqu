import sys
import csv

# Open CSV file and extract "comment" column
with open(sys.argv[1], mode ='r') as file:
    csvFile = csv.DictReader(file)
    strLst = []
    for line in csvFile:
        strLst.append( line['comment'] )

# Convert list items to floats
numLst = [float(strNum) for strNum in strLst]

# Target comment rate threshold (in %) to test for
cmntRateThres = sys.argv[2]

# Exclude last item as it is not a distinct comment rate but the sum
for cmntRate in numLst[:-1]:
    # Use non-zero exit code if comment rate is below threshold.
    # This allows for easy employment in continuous integration systems.
    if cmntRate < float(cmntRateThres):
        print(str( sys.argv[0] )
              + ': FAIL (comment rate below ' + cmntRateThres + ' %)')
        sys.exit(1)

sys.exit(0)
