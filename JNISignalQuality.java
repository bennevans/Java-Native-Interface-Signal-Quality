

public class JNISignalQuality{

	public native int nativeSignalQuality();

	static	{
		System.loadLibrary("JNISignalQuality");
	}

	public int getSignalQuality(){
		return nativeSignalQuality();
	}

	public static void main(String args[]){
		System.out.println((new JNISignalQuality()).getSignalQuality());
		return;
	}

}

