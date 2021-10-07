using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;

public class RandomScale : MonoBehaviour
{
	public Vector3 lowerBound;
	public Vector3 upperBound;

	[DllImport("RandomObjectScaler")]
	public static extern void SetScaleBounds(Vector3 lower, Vector3 upper);

	[DllImport("RandomObjectScaler")]
	public static extern Vector3 FetchRandomScale();

    // Start is called before the first frame update
    void Start()
    {
        SetScaleBounds(lowerBound, upperBound);
    }

	static public Vector3 GetRandomScale()
	{
		return FetchRandomScale();
	}
}
