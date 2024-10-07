package study.sanghwa.subject.phoneBook;

import java.io.BufferedReader;
import java.io.FileDescriptor;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) throws IOException {
		final PhoneBook phoneBook = new PhoneBook();
		phoneBook.run();
	}
}
