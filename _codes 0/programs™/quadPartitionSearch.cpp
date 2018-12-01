bool quadPartitionSearch(int rMin,  int rMax,  int cMin,  int cMax,  int key)
{
	if (rMin > rMax || cMin > cMax) return false;

	else if (rMin == rMax && cMin == cMax)
	{
		if (grid[rMin][cMin] == key)
        {
			x = rMin;
			y = cMin;
			return true;
		}
		else return false;
	}
	else if (grid[rMin][cMin] <= key && grid[rMax][cMax] >= key)
    {
		int rMid = (rMin + rMax) / 2;
		int cMid = (cMin + cMax) / 2;
		bool flag;
		if(grid[rMid][cMid] == key)
		{
			x=rMid;
			y=cMid;
			return true;
		}
		else if (grid[rMid][cMid] > key)
		{
			if (quadPartitionSearch(rMin, rMid, cMin, cMid, key)) return true;
		}
		else
		{
			if (quadPartitionSearch(rMid, rMax, cMid + 1, cMax, key)) return true;
			if (quadPartitionSearch(rMin, rMid, cMid + 1, cMax, key)) return true;
			if (quadPartitionSearch(rMid + 1, rMax, cMin, cMid, key)) return true;

		}
	}
	return false;
}
