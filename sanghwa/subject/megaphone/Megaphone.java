import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Megaphone {

	// 사용자 입력받는 버전
	public static void main(String[] args) throws IOException {
		BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

		System.out.println(buffer.readLine().toUpperCase());
	}

	// args 사용 버전
	// public static void main(String[] args) {
	// 	for (String arg : args) {
	// 		System.out.print(arg.toUpperCase());
	// 		System.out.print(" ");
	// 	}
	// }

	// StringBuilder 사용 버전
	// public static void main(String[] args) {
	// 	StringBuilder builder = new StringBuilder();
	// 	for (int i = 0; i < args.length; i++) {
	// 		builder.append(args[i].toUpperCase());
	// 		if (i != args.length - 1) {
	// 			builder.append(" ");
	// 		}
	// 	}
	// 	System.out.println(builder);
	// }

}
