bool IgualMargenError(int d,int m,float p)
{
	return (m>(d*(1-p)) && m<(d*(1+p)));
}

bool Comparar(int *d,int *m)
{
	return (IgualMargenError(d[0],m[0],0.1)&&IgualMargenError(d[1],m[1],0.18)&&IgualMargenError(d[2],m[2],0.18)&&IgualMargenError(d[3],m[3],0.18)&&IgualMargenError(d[4],m[4],0.18));
}