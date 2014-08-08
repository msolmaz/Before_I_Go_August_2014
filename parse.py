input_filep1 = open("k1.txt")
input_file0 = open("k0.txt")
input_filem1 = open("km1.txt")

linesp1 = input_filep1.readlines()
lines0 = input_file0.readlines()
linesm1 = input_filem1.readlines()

print len(linesp1)

# Single sensitive decay
eff_type = -4
# Two sensitive decays
# eff_type = -2

mass_value = ""

for i in range(len(linesp1)):
    if len(linesp1[i].split()) > 3:
        if lines0[i].split()[0] != "&":
            # print lines0[i].split()[0]
            mass_value = lines0[i].split()[0]
            mass_x = linesp1[i].split()[2]
        print "mH =", mass_value, "mX =", mass_x, "ctau =", linesp1[i].split()[-6]
        print lines0[i].split()[eff_type], "+", linesp1[i].split()[eff_type], "-", linesm1[i].split()[eff_type]
        if float(lines0[i].split()[eff_type]) != 0:
            reldiffp = (float(linesp1[i].split()[eff_type]) - float(lines0[i].split()[eff_type]))/float(lines0[i].split()[eff_type])
            reldiffm = (float(lines0[i].split()[eff_type]) - float(linesm1[i].split()[eff_type]))/float(lines0[i].split()[eff_type])
            print "max relative =", max(reldiffp, reldiffm)
        else:
            print "max relative = N/A"
        print ""
    # break
