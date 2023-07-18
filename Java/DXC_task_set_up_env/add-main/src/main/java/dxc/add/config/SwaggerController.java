package dxc.add.config;

import org.springframework.context.annotation.Profile;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
//@Profile(value={"dev","locale"})
public class SwaggerController {

    @GetMapping("/")
    public String index() {
        return "redirect:/swagger-ui.html";
    }

}
