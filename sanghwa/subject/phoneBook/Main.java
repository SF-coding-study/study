package study.sanghwa.subject.phoneBook;

import java.io.BufferedReader;
import java.io.FileDescriptor;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	static final String EXIT = "EXIT";
	static final String ADD = "ADD";
	static final String SEARCH = "SEARCH";

	static ArrayList<String> commands = new ArrayList<>();

	static final PhoneBook phoneBook = new PhoneBook();

	public static void main(String[] args) throws IOException {

		BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
		setCommands();

		String command;
		while (true) {
			System.out.print("Enter Command(ADD, SEARCH, EXIT) : ");

			if ((command = buffer.readLine()) == null) {
				System.out.println("EOF");
				return;
			}

			if (!commands.contains(command)) {
				System.out.println("Wrong Command!! (ADD, SEARCH, EXIT)");
			} else if (command.equals(EXIT)) {
				System.out.println("EXIT program!");
				return;
			} else {
				executeCommand(command);
			}
		}
	}

	private static void setCommands() {
		for (int i = 0; i < 3; i++) {
			commands.add(EXIT);
			commands.add(ADD);
			commands.add(SEARCH);
		}
	}

	private static void executeCommand(String command) throws IOException {
		if (command.equals(ADD)) {
			phoneBook.commandAdd();
		} else if (command.equals(SEARCH)) {
			phoneBook.commandSearch();
		}
	}
}
