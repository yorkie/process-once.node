{
  "targets": [
    {
      "target_name": "processonce",
      "sources": ["src/api.cc"],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
    },
  ],
}