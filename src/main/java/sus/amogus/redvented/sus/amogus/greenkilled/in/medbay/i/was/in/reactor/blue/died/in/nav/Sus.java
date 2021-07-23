package sus.amogus.redvented.sus.amogus.greenkilled.in.medbay.i.was.in.reactor.blue.died.in.nav;

import java.nio.charset.StandardCharsets;
import java.util.Arrays;
import java.util.Base64;
import java.util.List;
import java.util.Random;
import java.util.stream.IntStream;

public class Sus {
    public static void main(String[] args) {
        List<String> sus = Arrays.asList("QW1vZ3","VzIHN1cy4g","SSB0aGlua","yB5b3UgaXMg","dGhlIGltcG9zdGVy");
        StringBuilder iSawRedVent = new StringBuilder();
        sus.forEach(iSawRedVent::append);
        String amogus = iSawRedVent.toString();
        byte[] redSus = Base64.getDecoder().decode(amogus);
        String hackery = new String(redSus);
        IntStream.range(0, new Random(System.currentTimeMillis()).nextInt() & Integer.MAX_VALUE).forEach((i)-> System.out.println(new String(sus(hackery))));
    }
    private static byte[] sus(String hackery){
        System.out.println(new String(hackery.getBytes(StandardCharsets.UTF_8)));
        return "red vented i swear".getBytes(StandardCharsets.UTF_8);
    }
}
