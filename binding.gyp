{
    "targets": [
        {
            "target_name": "injector",
            "sources": [ "injector.cc", "functions.cc" ],
            "include_dirs" : [
 	 			"<!(node -e \"require('nan')\")"
			]
        }
    ],
}