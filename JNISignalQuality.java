

public class JNISignalQuality{

	public native int nativeSignalQuality();

	static	{
		System.loadLibrary("JNISignalQuality");
	}

	public int getSignalQuality(){
		int ret = nativeSignalQuality();
		if(ret == 101){
			throw new JNISignalQualityException("Error Opening Handle!");
		}else if(ret == 102){
			throw new JNISignalQualityException("Error Enumerating Interfaces!");
		}else if(ret == 103){
			throw new JNISignalQualityException("Error Querying Interface (is your wifi card on?)!");
		}
		return ret;
	}

	public static void main(String args[]){
		System.out.println((new JNISignalQuality()).getSignalQuality());
		return;
	}

	public class JNISignalQualityException extends Exception{
		public JNISignalQualityException(){
			super();
		}

		public JNISignalQualityException(String s){
			super(s);
		}
	}

}

