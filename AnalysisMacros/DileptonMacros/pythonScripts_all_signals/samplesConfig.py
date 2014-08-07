# Different combination of channels, number of exotics, pdg is of exotics, factors to reweight lifetime by
massesAndCtau=[
            ['H',1000,350,3500],
            ['H',1000,150,1000],
            ['H',1000,50,400],
            ['H',1000,20,150],
            ['H',400,150,4000],
            ['H',400,50,800],
            ['H',400,20,400],
            ['H',200,50,2000],
            ['H',200,20,700],
            ['H',125,50,5000],
            ['H',125,20,1300],
            ['C',1500,494,1600],
            ['C',1000,148,600],
            ['C',350,148,1730],
            ['C',120,48,1650],
               ]

signatureMap = {'H':'HTo2LongLivedTo4F', 'C':'Chi0ToNuLL'}
#signatureMap = {'H':'HTo2LongLivedTo4F'}

# If you are considering collinearity method or not
# Alternative is original d0 signing analysis
useCollinearityMethod = True

# These efficiencies are for a candidate to pass removed lifetime cirteria
removedLifetimeSelection = False

## ALL SAMPLES
#channels=["2muTrack", "2saMu"]
#channels=["2muTrack"]
channels=["2saMu"]
#### channels=["2globalOrTrackerMu"]
nExo=["one","two"]
signalPdg=["6001113","6002113","6003113","1000022"]
#signalPdg=["1000022"]
#signalPdg=["6001113","6002113","6003113"]
lifeTimeFactors=[0.01,0.02,0.04,0.06,0.08,0.1,0.2,0.4,0.6,0.8,1.,2.,4,6,8,10,20,40,60,80,100]
#lifeTimeFactors=[0.001,0.002,0.004,0.006,0.008,0.01,0.02,0.04,0.06,0.08,0.1,0.2,0.4,0.6,0.8,1.,2,4.,6.,8.,10]

### DEBUG
# channels=["2eTrack"]
# nExo=["one"]
# signalPdg=["6003113","1000022"]
# lifeTimeFactors=[1.,2.,10.]
# lifeTimeFactors=[0.01,0.02,0.04,0.06,0.08,0.1,0.2,0.4,0.6,0.8,1.,2.,4,6,8,10,20,40,60,80,100]
# lifeTimeFactors=[1.]
# lifeTimeFactors=[0.01,0.1,1.]
