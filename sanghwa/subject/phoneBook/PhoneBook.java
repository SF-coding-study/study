package study.sanghwa.subject.phoneBook;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.regex.Pattern;

public class PhoneBook {

	private final ArrayList<Contact> contacts;
	int MAX_SIZE = 8;

	static BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));

	public PhoneBook() {
		contacts = new ArrayList<>();
	}

	public void commandAdd() throws IOException {
		Contact contact = getInput();
		addContact(contact);
	}

	private void addContact(Contact contact) {
		int targetIdx = contacts.size();
		if (targetIdx == MAX_SIZE) {
			targetIdx %= MAX_SIZE;
		}
		if (targetIdx == 0 && !contacts.isEmpty()) {
			contacts.remove(targetIdx);
		}
		contacts.add(targetIdx, contact);
	}

	public void commandSearch() throws IOException {
		final String ERROR_MESSAGE = "Wrong index value(0~" + (contacts.size() - 1) + ")";

		System.out.println(getContactsDisplayString());
		System.out.println("choose index(0~" + (contacts.size() - 1) + ")");
		String idxString = buffer.readLine();

		Pattern pattern = Pattern.compile("^-?\\d+$");

		if (pattern.matcher(idxString).matches()) {
			int idx = Integer.parseInt(idxString);
			if (idx >= contacts.size() || idx < 0) {
				System.out.println(ERROR_MESSAGE);
				return;
			}
			System.out.println(displayContactByIndex(idx));
		} else {
			System.out.println(ERROR_MESSAGE);
		}
	}

	private String displayContactByIndex(int idx) throws IllegalArgumentException{
		Contact contact = contacts.get(idx);
		return contactDisplayString(contact);
	}

	private String contactDisplayString(Contact contact) {
		return contact.toString();
	}

	private String getContactsDisplayString() {
		StringBuilder builder = new StringBuilder();

		buildHeader(builder);
		buildBody(builder);

		return builder.toString();
	}

	private void buildHeader(StringBuilder builder) {
		builder.append("|").append("index")
			.append("|").append("first name")
			.append("|").append("last name")
			.append("|").append("nickname").append("|").append("\n");
	}

	private void buildBody(StringBuilder builder) {
		for (int idx = 0; idx < contacts.size(); idx++) {
			Contact contact = contacts.get(idx);
			String firstName = cutOverTen(contact.firstName());
			String lastName = cutOverTen(contact.lastName());
			String nickname = cutOverTen(contact.nickname());

			builder.append(String.format("|%d|%10s|%10s|%10s|\n",
				idx, firstName, lastName, nickname));
		}
	}

	private String cutOverTen(String str) {
		if (str.length() <= 10) {
			return str;
		}
		return str.substring(0, 8) + ".";
	}

	private Contact getInput() throws IOException {
		String[] fields = {"firstName", "lastName", "nickname", "phoneNumber", "darkestSecret"};
		String[] values = new String[5];

		while (true) {
			boolean allFieldsValid = true;

			for (int i = 0; i < fields.length; i++) {
				String input = readField(fields[i]);
				if (input == null) {
					return null;
				}
				if (input.isEmpty()) {
					System.out.println("Field cannot be empty");
					allFieldsValid = false;
					break;
				}
				values[i] = input;
			}

			if (allFieldsValid) {
				return Contact.of(values);
			}
		}
	}

	private String readField(String fieldName) throws IOException {
		System.out.print(fieldName + " : ");
		return readLineWithEOFCheck();
	}

	private String readLineWithEOFCheck() throws IOException {
		String input = buffer.readLine();

		if (input == null) {
			System.out.println("EOF");
		}
		return input;
	}

}
