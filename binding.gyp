{
  "targets": [
    {
      "target_name": "fftw",
      "sources": [ "fftw.cc" ],
      "include_dirs" : [
        "<!(node -e \"require('nan')\")"
      ],
      "conditions": [
        [ "OS==\"mac\"",
          {
            "link_settings": {
              "libraries": [
                "-lfftw3", "-lm"
              ]
            }
          }
        ]
      ]
    }
  ]
}
