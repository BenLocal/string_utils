package j;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Your code here
        int a = (int) StringUtils.convertToObject("1", "int");
        System.out.println(a);

        int[] arr = (int[]) StringUtils.convertToObject("[1,2,3]", int[].class.getName());
        System.out.println(StringUtils.convertToString(arr));

        char c = (char) StringUtils.convertToObject("国", "char");
        int baseCodePoint = (int) c;
        List<Character> result = new java.util.ArrayList<>();
        for (int i = 1; i <= 5; i++) {
            int nextCodePoint = baseCodePoint + i;
            if (Character.isValidCodePoint(nextCodePoint)) {
                result.add((char) nextCodePoint);
            }
        }
        for (Character character : result) {
            System.out.print(character + " ");
        }
        System.out.println();
        System.out.println(StringUtils.convertToString(c));
    }

    public static class StringUtils {
        public static String convertToString(Object obj) {
            if (obj instanceof String) {
                return (String) obj;
            } else if (obj instanceof int[]) {
                StringBuilder sb = new StringBuilder();
                for (int i : (int[]) obj) {
                    sb.append(i).append(",");
                }
                if (sb.length() > 0) {
                    sb.setLength(sb.length() - 1); // Remove trailing comma
                }
                return String.format("[%s]", sb.toString());
            } else if (obj instanceof Integer) {
                return String.valueOf(obj);
            } else if (obj instanceof Character) {
                return String.valueOf(obj);
            }
            return null;
        }

        public static Object convertToObject(String str, String typeName) {
            if (str == null || typeName == null) {
                return null;
            }

            if (typeName.equals(String.class.getName())) {
                return str;
            } else if (typeName.equals("int")) {
                return Integer.parseInt(str);
            } else if (typeName.equals(int[].class.getName())) {
                str = str.substring(1, str.length() - 1); // Remove brackets
                String[] parts = str.split(",");
                int[] arr = new int[parts.length];
                for (int i = 0; i < parts.length; i++) {
                    arr[i] = Integer.parseInt(parts[i].trim());
                }
                return arr;
            } else if (typeName.equals("char")) {
                if (str.length() == 1) {
                    return str.charAt(0);
                } else {
                    throw new IllegalArgumentException("String must be a single character for char type");
                }
            }
            return null;
        }
    }
}