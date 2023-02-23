import numpy as np
from Potential_Attractions import *
from Potential_Repulsion import *
from Distance_Euclidian import *
#Author: Steven Craig
#Function for viapoints on the path
#returned as an array of points
#Takes the start position and goal position XYs. Output an array of the via points ((x1,y1),(x2,y2),(x3,y3)....)
#xobj is an array of all obstacle x points, y is the same but for y points
def PathPlanner(x,y,xgoal,ygoal,xobj,yobj,Q,D): #you are currently trying to add this in, this is the path from a poiint using position and force ads velocity
    PathComplete = 0 #This turns to 1 and ends the function once end effector has reached target position (minimum of pootential)
    PathPointsx = [x] #First X and Y points
    PathPointsy = [y] #These are in different arrays cos tuples suck. The 'zip' function at the end turns them into a tuple
    i = 0
    while PathComplete == 0:
        diffattx,diffatty = PotentialAttractionChange(PathPointsx[i],PathPointsy[i],xgoal,ygoal,D) #what is the attractive slope of the current pos
        diffrepx,diffrepy = PotentialRepulsionChange(PathPointsx[i],PathPointsy[i],xobj,yobj,Q) #what is the repulsive slope of current pos
        difx = diffattx+diffrepx #total force (attract and repulsive combined)
        dify = diffatty+diffrepy
        d = EuclidianDistance(x,y,xgoal,ygoal) #distance to objects
        if abs(difx) <0.2 and abs(dify) <0.2 and d > 0.1: #if gradient is small then we've reached goal (local minima issues here)
            PathComplete = 1
        if abs(difx) < 0.1 and abs(dify) < 0.1:
            pass
            #add get out of minima here
        else:
            #print('Iteration: ',i,'diff x,y: ',diffrepx,diffrepy)
            nextx = PathPointsx[i] - difx*0.2 #make next point (with scaling factor)
            nexty = PathPointsy[i] - dify*0.2 
            x = nextx
            y = nexty
            PathPointsx.append(x) #add next point to list of points
            PathPointsy.append(y)
        i += 1
    PathPoints = list(zip(PathPointsx,PathPointsy)) #put into a tuple
    return PathPoints