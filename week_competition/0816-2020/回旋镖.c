
bool isBoomerang(int** points, int pointsSize, int* pointsColSize){
    //回旋镖特征
    /*
        三角形，则只需要判断三个点构成三角形
    */
   
    float area = 0;//求三角形面积

#if 0
     int size = 0;
    float sizde1,sizde2,sizde3;

    sizde1 = sqrt(pow((points[0][0] - points[1][0]),2) + pow((points[0][1] - points[1][1]),2));
    sizde2 = sqrt(pow((points[2][0] - points[1][0]),2) + pow((points[2][1] - points[1][1]),2));
    sizde3 = sqrt(pow((points[0][0] - points[2][0]),2) + pow((points[0][1] - points[2][1]),2));

    //判断等边

    if (sizde1 == sizde2)
    {
        size += 1;
    }

    if ( sizde1 == sizde3)
    {
        size += 1;
    }

    if (sizde2 == sizde3)
    {
        size += 1;
    }
#endif
    
	area = (points[0][0] * (points[1][1] -points[2][1]) + points[1][0] * (points[2][1] - points[0][1]) + points[2][0] * (points[0][1] - points[1][1]));

    if (abs(area) > 0)
    {
        return true;
    }

    return false;
}
