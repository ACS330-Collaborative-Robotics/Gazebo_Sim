#Function for the Potential Repulsion
#Inputs current position and obstacle postition XYs. Outputs is a single value for Potential at those coordinates
#Author:Steven Craig
from Distance_Euclidian import *
import math
import numpy as np
def PotentialRepulsion(x,y,z,xobj,yobj,zobj,Q):
    SF = 100
    PotentialRep = 0
    for objNum in range(len(xobj)):
        d = EuclidianDistance(x,y,z,xobj[objNum],yobj[objNum],zobj[objNum])
        if d <= Q[objNum]:
            PotentialRepcurrent = SF*((1/d)-(1/Q[objNum]))
        else:
            PotentialRepcurrent = 0
        if PotentialRepcurrent > 100:
            PotentialRepcurrent = 100
        PotentialRep += PotentialRepcurrent
    return PotentialRep

def PotentialRepulsion2d(x,y,xobj,yobj,Q):
    SF = 100
    PotentialRep = 0
    for objNum in range(len(xobj)):
        d = EuclidianDistance2d(x,y,xobj[objNum],yobj[objNum])
        if d <= Q[objNum]:
            PotentialRepcurrent = SF*((1/d)-(1/Q[objNum]))
        else:
            PotentialRepcurrent = 0
        if PotentialRepcurrent > 100:
            PotentialRepcurrent = 100
        PotentialRep += PotentialRepcurrent
    return PotentialRep

def PotentialRepulsionChange(x,y,z,xobj,yobj,zobj,xgoal,ygoal,zgoal,Q):
    allvectorsx = 0
    allvectorsy = 0
    allvectorsz = 0
    repulsionangle = 0
    for objNum in range(len(xobj)):
        #generate the vectors and angles
        homevect = [xgoal-x,ygoal-y,zgoal-z]
        objvect = (xobj[objNum]-x,yobj[objNum]-y,zobj[objNum]-z)
        anglegoal = math.atan2(homevect[1],homevect[0])
        angleobj = math.atan2(objvect[1],objvect[0])
        angle = angleobj-anglegoal
        zheight = z-zobj[objNum]
        d = EuclidianDistance2d(x,y,xobj[objNum],yobj[objNum])
        D = EuclidianDistance(x,y,z,xobj[objNum],yobj[objNum],zobj[objNum])
        zangle = math.atan2(zheight,d)
        SF = 2
        # deciding the direction of the tangent
        if angle > 0 or angle == 0:
            repulsionangle = anglegoal + 100
        if angle < 0:
            repulsionangle = anglegoal - 100

        if zheight >= 0:
            zrepangle = zangle - 100
        if zheight < 0:
            zrepangle = zangle + 100


        #deciding whether the obstacle is in range
        #if D<Q[objNum]:
            #print("in influence")
        repulsionvect = SF*math.cos(math.radians(angle))*math.cos(math.radians(repulsionangle)),SF*math.cos(math.radians(angle))*math.sin(math.radians(repulsionangle))
        repulsionvect = list(repulsionvect)
        zrep = SF*math.cos(math.radians(zangle))*math.sin(math.radians(zrepangle))
        if D > Q[objNum]:
            repulsionvect = 0,0
            zrep = 0
        else:
            print("zinfo:",zheight,zangle,zrepangle)
        #for x in range(len(repulsionvect)):
         #   if repulsionvect[x] > 3:
          #      repulsionvect[x]= 3
        allvectorsx += repulsionvect[0]
        allvectorsy += repulsionvect[1]
        allvectorsz += zrep
    return allvectorsx,allvectorsy,allvectorsz
