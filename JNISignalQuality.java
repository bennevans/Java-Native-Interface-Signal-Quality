

public class JNISignalQuality{

	public native String nativeSignalQuality();

	static	{
		System.loadLibrary("SignalQuality");
	}

	public int getSignalQuality(){
		return Integer.parseInt(nativeSignalQuality());
	}

	public static void main(String args[]){
		System.out.println((new JNISignalQuality()).getSignalQuality());
		return;
	}

}

